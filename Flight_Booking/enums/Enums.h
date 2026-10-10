#pragma once

enum class SeatStatus {
    Available,
    Held,
    Booked
};

enum class BookingStatus {
    Confirmed,
    Cancelled,
    Failed
};

enum class SeatClass {
    Economy,
    Business,
    FirstClass
};
