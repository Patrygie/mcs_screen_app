#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include "main.h"

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void map_update_value(uint32_t value){};
    virtual void tc_update_value(uint32_t value){};
    virtual void speed_update_value(uint32_t value){};
    virtual void diff_update_value(uint32_t value){};
    virtual void tsac_update_value(uint32_t value){};
    virtual void leng_update_value(uint32_t value){};
    virtual void linv_update_value(uint32_t value){};
    virtual void bat_update_value(uint32_t value){};
    virtual void rinv_update_value(uint32_t value){};
    virtual void reng_update_value(uint32_t value){};
    virtual void err_update_value(uint32_t value){};
    virtual void hv_update_value(uint32_t value){};
    virtual void low_update_value(uint32_t value){};
    virtual void p2d_update_value(uint32_t value){};
    virtual void ts_update_value(uint32_t value){};
    virtual void gas_update_value(uint32_t value){};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
