#pragma once

#include <optional>
#include <string>
#include <unordered_map>

class Registry {
    using ID = std::string;
    using FunctionPointer = void (*)();
    using Map = std::unordered_map<ID, FunctionPointer>;
public:
    static std::optional<FunctionPointer> find(const ID& id) {
        auto it = map.find(id);
        if (it == map.end()) {
            return {};
        }
        return it->second;
    };
    static void reg(ID id, FunctionPointer f) {
        map.emplace(id, f);
    }
private:
    inline static Map map;
};