#include "BloggingPlatform.h"
#include <iostream>
#include <algorithm>

BloggingPlatform::BloggingPlatform() : postCounter(1) {}

bool BloggingPlatform::userExists(const std::string& userId) const {
    return users.find(userId) != users.end();
}

bool BloggingPlatform::postExists(const std::string& postId) const {
    return posts.find(postId) != posts.end();
}

bool BloggingPlatform::registerUser(const std::string& userId, const std::string& username) {
    if (userExists(userId)) {
        return false; // User already exists
    }
    users[userId] = std::make_shared<User>(userId, username);
    return true;
}

std::string BloggingPlatform::createPost(const std::string& userId, const std::string& content) {
    if (!userExists(userId)) {
        std::cout << "Error: User " << userId << " not found.\n";
        return "";
    }

    std::string postId = "POST_" + std::to_string(postCounter++);
    auto newPost = std::make_shared<Post>(postId, userId, content);
    posts[postId] = newPost;

    std::cout << "[System] User " << users[userId]->getUsername() << " created post: " << postId << "\n";
    return postId;
}

bool BloggingPlatform::followUser(const std::string& followerId, const std::string& followeeId) {
    if (!userExists(followerId) || !userExists(followeeId) || followerId == followeeId) {
        return false; // Invalid operation dependency
    }
    users[followerId]->follow(followeeId);
    std::cout << "[System] " << users[followerId]->getUsername() << " is now following "
              << users[followeeId]->getUsername() << "\n";
    return true;
}

bool BloggingPlatform::likePost(const std::string& userId, const std::string& postId) {
    if (!userExists(userId) || !postExists(postId)) {
        return false;
    }
    posts[postId]->addLike();
    return true;
}

bool BloggingPlatform::commentOnPost(const std::string& userId, const std::string& postId, const std::string& text) {
    if (!userExists(userId) || !postExists(postId)) {
        return false;
    }
    posts[postId]->addComment(userId, text);
    return true;
}

std::vector<std::shared_ptr<Post>> BloggingPlatform::generateNewsFeed(const std::string& userId) {
    std::vector<std::shared_ptr<Post>> feed;
    if (!userExists(userId)) {
        return feed;
    }

    auto currentUser = users[userId];
    const auto& followingList = currentUser->getFollowing();

    // Pull-model news feed generation:
    // Traverses posts and filters for posts by followed users or own posts.
    for (const auto& pair : posts) {
        const auto& post = pair.second;
        if (followingList.find(post->getAuthorId()) != followingList.end() || post->getAuthorId() == userId) {
            feed.push_back(post);
        }
    }

    // Sort by timestamp descending (newest first)
    std::sort(feed.begin(), feed.end(), [](const std::shared_ptr<Post>& a, const std::shared_ptr<Post>& b) {
        return a->getTimestamp() > b->getTimestamp();
    });

    return feed;
}

void BloggingPlatform::printFeed(const std::string& userId) {
    std::cout << "\n--- News Feed for " << (userExists(userId) ? users[userId]->getUsername() : "Unknown") << " ---\n";
    auto feed = generateNewsFeed(userId);
    if (feed.empty()) {
        std::cout << "No posts to show.\n";
        return;
    }
    for (const auto& post : feed) {
        std::cout << "[" << post->getPostId() << "] "
                  << users[post->getAuthorId()]->getUsername() << " says: '"
                  << post->getContent() << "' | Likes: " << post->getLikes()
                  << " | Comments: " << post->getComments().size() << "\n";
    }
    std::cout << "---------------------------------\n";
}
