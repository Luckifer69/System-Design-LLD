#include <iostream>
#include <string>
#include "services/BloggingPlatform.h"

int main() {
    std::cout << "--- Starting Blogging Platform Workflow Simulation ---\n\n";

    BloggingPlatform platform;

    // Register Users
    platform.registerUser("U1", "Divyanshu");
    platform.registerUser("U2", "Aditya");
    platform.registerUser("U3", "Harshit");

    // Create Posts
    std::string p1 = platform.createPost("U1", "Just deployed the Faculty Load Balancer!");
    std::string p2 = platform.createPost("U2", "Working on some new ML pipelines.");
    std::string p3 = platform.createPost("U3", "Organizing the IEEE C++ contest this weekend.");

    // Network / Follow Workflow
    platform.followUser("U1", "U2"); // Divyanshu follows Aditya
    platform.followUser("U1", "U3"); // Divyanshu follows Harshit

    // Interactions
    platform.likePost("U2", p1);
    platform.likePost("U3", p1);
    platform.commentOnPost("U2", p1, "Great job on the zero conflicts!");

    // Generate Feed
    platform.printFeed("U1"); // Should see posts from self, Aditya, and Harshit
    platform.printFeed("U2"); // Should only see own posts (hasn't followed anyone)

    return 0;
}
