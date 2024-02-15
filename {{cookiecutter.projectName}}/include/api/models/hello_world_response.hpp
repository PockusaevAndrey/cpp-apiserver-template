//
// Created by Андрей Покусаев on 14.02.2024.
//

#ifndef {{cookiecutter.projectSlug}}_HELLO_WORLD_MODEL_HPP
#define {{cookiecutter.projectSlug}}_HELLO_WORLD_MODEL_HPP

#include <nlohmann/json.hpp>

namespace {{cookiecutter.projectSlug}}::server::model {
    class HelloWorldResponse {
    public:
        HelloWorldResponse();
        virtual ~HelloWorldResponse();
        void validate();

        std::string getResult() const;

        void setResult(std::string const &value);

        bool resultIsSet() const;

        void unsetResult();

        friend void to_json(nlohmann::json &j, const HelloWorldResponse &o);
        friend void from_json(const nlohmann::json &j, HelloWorldResponse &o);

    protected:
        std::string m_Result;
        bool m_ResultIsSet;
    };
}


#endif //{{cookiecutter.projectSlug}}_HELLO_WORLD_MODEL_HPP
