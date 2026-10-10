#include "Comment.h"

Comment::Comment(const std::string& a, const std::string& t)
    : authorId(a), text(t), timestamp(time(nullptr)) {}

std::string Comment::getAuthorId() const {
    return authorId;
}

std::string Comment::getText() const {
    return text;
}

time_t Comment::getTimestamp() const {
    return timestamp;
}
