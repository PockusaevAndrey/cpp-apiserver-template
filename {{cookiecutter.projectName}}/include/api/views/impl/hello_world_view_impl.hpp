//
// Created by Андрей Покусаев on 14.02.2024.
//

#ifndef {{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_IMPL_HPP
#define {{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_IMPL_HPP

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>
#include <nlohmann/json.hpp>

#include "api/views/hello_world_view.hpp"

namespace {{cookiecutter.projectSlug}}::server::view::impl {
class HelloWorldViewImpl : public {{cookiecutter.projectSlug}}::server::view::HelloWorldView  {
public:
HelloWorldViewImpl(std::shared_ptr<Pistache::Rest::Router>);
~HelloWorldViewImpl() {};

void get_hello(const std::optional<std::string> &name, Pistache::Http::ResponseWriter &response);

};
};

#endif //{{cookiecutter.projectSlug}}_HELLO_WORLD_VIEW_IMPL_HPP
