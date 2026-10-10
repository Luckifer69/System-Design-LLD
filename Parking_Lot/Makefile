CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -I.
TARGET = parking_lot

SRCS = main.cpp \
       models/Vehicle.cpp \
       models/ParkingSpot.cpp \
       models/Floor.cpp \
       models/Ticket.cpp \
       strategies/HourlyPricingStrategy.cpp \
       services/ParkingLot.cpp \
       gates/EntryGate.cpp \
       gates/ExitGate.cpp

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
