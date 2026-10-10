#include "Post.h"

Post::Post(const std::string& pId, const std::string& aId, const std::string& txt)
    : postId(pId), authorId(aId), content(txt), likes(0), timestamp(time(nullptr)) {}

std::string Post::getPostId() const {
    return postId;
}

std::string Post::getAuthorId() const {
    return authorId;
}

std::string Post::getContent() const {
    return content;
}

time_t Post::getTimestamp() const {
    return timestamp;
}

int Post::getLikes() const {
    return likes;
}

void Post::addLike() {
    likes++;
}

void Post::addComment(const std::string& userId, const std::string& text) {
    comments.emplace_back(userId, text);
}

const std::vector<Comment>& Post::getComments() const {
    return comments;
}
