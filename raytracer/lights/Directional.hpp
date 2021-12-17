#include "Light.hpp"
#include "../utilities/Vector3D.hpp"

class Directional: public Light{
    protected:
        Vector3D direction;
    public:
        Directional();
        ~Directional() = default;
        virtual Vector3D get_direction(const ShadeInfo& src) const;
        virtual RGBColor L(const ShadeInfo& src) const;
};
