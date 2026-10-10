CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -I.
TARGET = flight_booking

SRCS = main.cpp \
       models/Passenger.cpp \
       models/Seat.cpp \
       models/Flight.cpp \
       models/Booking.cpp \
       services/PaymentGateway.cpp \
       services/FlightSystem.cpp

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
