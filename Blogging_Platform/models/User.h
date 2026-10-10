#pragma once

#include <string>
#include <unordered_set>

class User {
private:
    std::string userId;
    std::string username;
    std::unordered_set<std::string> following; // Optimized for O(1) lookups

public:
    User(const std::string& id, const std::string& name);

    std::string getUserId() const;
    std::string getUsername() const;

    void follow(const std::string& targetUserId);
    void unfollow(const std::string& targetUserId);
    const std::unordered_set<std::string>& getFollowing() const;
};
