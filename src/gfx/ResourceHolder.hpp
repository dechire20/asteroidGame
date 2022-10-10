#ifndef GFX_RESOURCEHOLDER_HPP
#define GFX_RESOURCEHOLDER_HPP

#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <cassert>

namespace Textures{
    enum ID {Spaceship, SmallStar, MedStar, Asteroid};
}

namespace Fonts{
    enum ID {Sansation};
}

template<typename Resource, typename Identifier>
class ResourceHolder{
    public:
        void load(Identifier id, const std::string &filename);
        template<typename Parameter>
        void load(Identifier id, const std::string &filename, Parameter secondParam);
        Resource &get(Identifier id);
        const Resource &get(Identifier id) const;
    
    private:
        std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
#include "ResourceHolder.inl"
#endif
