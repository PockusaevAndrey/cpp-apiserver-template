//
// Created by Андрей Покусаев on 14.02.2024.
//

#include "api/views/impl/hello_world_view_impl.hpp"
#include "api/models/hello_world_response.hpp"
namespace {{cookiecutter.projectSlug}}::server::view::impl {
    using namespace {{cookiecutter.projectSlug}}::server::model;
HelloWorldViewImpl::HelloWorldViewImpl(std::shared_ptr<Pistache::Rest::Router> rtr) : HelloWorldView(rtr) {}
void HelloWorldViewImpl::get_hello(const std::optional<std::string> &name, Pistache::Http::ResponseWriter &response) {
    HelloWorldResponse resp;
    if (name.has_value()) {
        resp.setResult("Hello, " + name.value());
        response.send(Pistache::Http::Code::Ok, nlohmann::json(resp).dump());
    } else {
        response.send(Pistache::Http::Code::Bad_Request, "name is null");
    }
}
};