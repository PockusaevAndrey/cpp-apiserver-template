//
// Created by Андрей Покусаев on 14.02.2024.
//

#include "api/models/hello_world_response.hpp"

namespace {{cookiecutter.projectSlug}}::server::model {

    HelloWorldResponse::HelloWorldResponse() {
        m_Result = "";
        m_ResultIsSet = false;
    }

    HelloWorldResponse::~HelloWorldResponse(){

    }
    void HelloWorldResponse::validate() {
        if (m_ResultIsSet && m_Result == ""){

        }
    }
    std::string HelloWorldResponse::getResult() const {
        return m_Result;
    }

    void HelloWorldResponse::setResult(std::string const &value) {
        m_Result = value;
        m_ResultIsSet = true;
    }

    bool HelloWorldResponse::resultIsSet() const {
        return m_ResultIsSet;
    }
    void HelloWorldResponse::unsetResult() {
        m_ResultIsSet = false;
    }

    void to_json(nlohmann::json &j, const HelloWorldResponse &o) {
        j = nlohmann::json();
        if (o.resultIsSet())
            j["result"] = o.m_Result;
    }

    void from_json(const nlohmann::json &j, HelloWorldResponse &o) {
        if (j.find("result") != j.end()) {
            j.at("result").get_to(o.m_Result);
            o.m_ResultIsSet = true;
        }
    }
}