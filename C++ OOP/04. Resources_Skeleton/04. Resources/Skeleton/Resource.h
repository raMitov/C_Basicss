#ifndef RESOURCE_H

#define RESOURCE_H

#include <utility>
#include <sstream>
#include <string>
#include "ResourceType.h"

namespace SoftUni {

    std::istream & operator >> (std::istream & iss, enum ResourceType & t) {
        std::string buf;
        iss >> buf;
        if (buf == "Presentation") {
            t = ResourceType::PRESENTATION;
        }
        else if (buf == "Video") {
            t = ResourceType::VIDEO;
        }
        else if (buf == "Demo") {
            t = ResourceType::DEMO;
        }
        return iss;
    }

    class Resource {
        int id;
        ResourceType type;
        std::string linkTo;
    public:
        ResourceType getType() const { return this->type; }
        int getId() const { return this->id; }
        std::string getLinkTo() const { return this->linkTo; }

        friend std::istream& operator>>(std::istream& iss, Resource& res) {
            iss >> res.id;
            iss >> res.type;
            getline(iss, res.linkTo);
            return iss;
        }

    };
    std::ostream& operator<<(std::ostream& os,const Resource & t) {
        os << t.getId();
        os << t.getType();
        os << t.getLinkTo();
        return os;
    }

}


#endif // !RESOURCE_H