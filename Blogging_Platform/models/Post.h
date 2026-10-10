#pragma once

#include <string>
#include <vector>
#include <ctime>
#include "Comment.h"

class Post {
private:
    std::string postId;
    std::string authorId;
    std::string content;
    int likes;
    std::vector<Comment> comments;
    time_t timestamp;

public:
    Post(const std::string& pId, const std::string& aId, const std::string& txt);

    std::string getPostId() const;
    std::string getAuthorId() const;
    std::string getContent() const;
    time_t getTimestamp() const;
    int getLikes() const;

    void addLike();
    void addComment(const std::string& userId, const std::string& text);
    const std::vector<Comment>& getComments() const;
};
