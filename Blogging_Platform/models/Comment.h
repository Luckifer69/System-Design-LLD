#pragma once

#include <string>
#include <ctime>

class Comment {
private:
    std::string authorId;
    std::string text;
    time_t timestamp;

public:
    Comment(const std::string& a, const std::string& t);

    std::string getAuthorId() const;
    std::string getText() const;
    time_t getTimestamp() const;
};
