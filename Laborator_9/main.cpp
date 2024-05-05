#include <bits/stdc++.h>

template <typename KeyType, typename ValueType>
class Map {
private:
    std::vector<std::pair<KeyType, ValueType>> data;

public:
    void Set(const KeyType& key, const ValueType& value) {
        for (auto& pair : data) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        data.push_back(std::make_pair(key, value));
    }

    bool Get(const KeyType& key, ValueType& value) {
        for (const auto& pair : data) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    size_t Count() const {
        return data.size();
    }

    void Clear() {
        data.clear();
    }

    bool Delete(const KeyType& key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<KeyType, ValueType>& other) const {
        for (const auto& pair : other.data) {
            bool found = false;
            for (const auto& thisPair : data) {
                if (thisPair.first == pair.first) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    auto begin() {
        return data.begin();
    }

    auto end() {
        return data.end();
    }
};

int main() {
    Map<int, const char *> m;
    m.Set(10, "C++");
    m.Set(20, "test");
    m.Set(30, "Poo");
    int index = 0;
    for (const auto& [key, value] : m) {
        std::cout << "Index:" << index << ", Key=" << key << ", Value=" << value << std::endl;
        index++;
    }

    m.Set(20, "result");
    index = 0;
    for (const auto& [key, value] : m) {
        std::cout << "Index:" << index << ", Key=" << key << ", Value=" << value << std::endl;
        index++;
    }

    return 0;
}
