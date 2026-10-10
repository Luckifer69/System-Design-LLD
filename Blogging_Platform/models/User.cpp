#include "User.h"

User::User(const std::string& id, const std::string& name)
    : userId(id), username(name) {}

std::string User::getUserId() const {
    return userId;
}

std::string User::getUsername() const {
    return username;
}

void User::follow(const std::string& targetUserId) {
    following.insert(targetUserId);
}

void User::unfollow(const std::string& targetUserId) {
    following.erase(targetUserId);
}

const std::unordered_set<std::string>& User::getFollowing() const {
    return following;
}
