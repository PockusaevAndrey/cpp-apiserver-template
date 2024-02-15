//
// Created by Андрей Покусаев on 14.02.2024.
//

#ifndef {{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_HPP
#define {{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_HPP

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <nlohmann/json.hpp>

namespace {{cookiecutter.projectSlug}}::server::view {
    class HelloWorldView {
    public:
        HelloWorldView(std::shared_ptr<Pistache::Rest::Router>);

        virtual ~HelloWorldView() {};

        void init();

        const std::string base = "/{{cookiecutter.projectName}}/{{cookiecutter.projectVersion}}";

    private:
        void setupRoutes();

        void get_hello_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
        void default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

        std::shared_ptr<Pistache::Rest::Router> router;

        virtual void get_hello(const std::optional<std::string> &name, Pistache::Http::ResponseWriter &response) = 0;


    };
}


#endif //{{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_HPP
