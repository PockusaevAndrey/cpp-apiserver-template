//
// Created by Андрей Покусаев on 14.02.2024.
//

#include "api/views/hello_world_view.hpp"
#include "utils/helpers.hpp"

namespace {{cookiecutter.projectSlug}}::server::view {
using namespace {{cookiecutter.projectSlug}}::server::utils::helpers;
    HelloWorldView::HelloWorldView(std::shared_ptr<Pistache::Rest::Router> rtr){
        router = rtr;
    }

    void HelloWorldView::init() {
        setupRoutes();
    }

    void HelloWorldView::setupRoutes(){
        using namespace Pistache::Rest;

        Routes::Get(*router, base + "/hello", Routes::bind(&HelloWorldView::get_hello_handler, this));
        router->addCustomHandler(Routes::bind(&HelloWorldView::default_handler, this));
    }

    void HelloWorldView::get_hello_handler(const Pistache::Rest::Request & request,
                           Pistache::Http::ResponseWriter response) {
        auto name = request.query().get("name");
        try {
            this->get_hello(name, response);
        } catch (nlohmann::detail::exception &e) {
            //send a 400 error
            response.send(Pistache::Http::Code::Bad_Request, e.what());
            return;
        } catch (std::exception &e) {
            //send a 500 error
            response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
            return;
        }
    }

    void HelloWorldView::default_handler(const Pistache::Rest::Request &,
                                                 Pistache::Http::ResponseWriter response) {
        response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
    }

};