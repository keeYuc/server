#include<jsoncpp/json/json.h>
#include<fstream>
#include<iostream>


int main()
{
    Json::Value obj;
    // obj.append(123);
    // Json::Value fuck;
    // fuck["草拟d"] = "sb";
    // obj.append(fuck);
    // std::fstream file("fuck.json", std::ios::out);
    // Json::FastWriter w;
    // file << w.write(obj);
    std::fstream file("fuck.json", std::ios::in);
    Json::Reader r;
    r.parse(file, obj);
    if (obj.isArray())
    {
        for (int i;i < obj.size(); i++)
        {

            if (obj[i].isInt())
            {
                std::cout << obj[i].asInt() << std::endl;
            }
            if (obj[i].isObject())
            {
                std::cout << obj[i]["草拟d"].asString() << std::endl;
            }
        }
    }






}

