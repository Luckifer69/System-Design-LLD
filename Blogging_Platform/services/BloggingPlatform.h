#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "../models/User.h"
#include "../models/Post.h"

class BloggingPlatform {
private:
    std::map<std::string, std::shared_ptr<User>> users;
    std::map<std::string, std::shared_ptr<Post>> posts;
    int postCounter;

    // Helper methods to validate dependencies
    bool userExists(const std::string& userId) const;
    bool postExists(const std::string& postId) const;

public:
    BloggingPlatform();

    // 1. User Management
    bool registerUser(const std::string& userId, const std::string& username);

    // 2. Post Creation Workflow
    std::string createPost(const std::string& userId, const std::string& content);

    // 3. Social Interaction: Follow
    bool followUser(const std::string& followerId, const std::string& followeeId);

    // 4. Content Interaction: Like & Comment
    bool likePost(const std::string& userId, const std::string& postId);
    bool commentOnPost(const std::string& userId, const std::string& postId, const std::string& text);

    // 5. Feed Generation (Pull-based News Feed Model)
    std::vector<std::shared_ptr<Post>> generateNewsFeed(const std::string& userId);
    void printFeed(const std::string& userId);
};
