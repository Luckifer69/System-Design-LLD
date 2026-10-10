CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -I.
TARGET = blogging_platform

SRCS = main.cpp \
       models/Comment.cpp \
       models/User.cpp \
       models/Post.cpp \
       services/BloggingPlatform.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe

run: $(TARGET)
	./$(TARGET)
