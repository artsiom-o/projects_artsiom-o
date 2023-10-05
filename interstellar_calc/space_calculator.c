#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables
    char starName[50], departure_point[50], spaceship_name[50];
    double distance, speed, lorentz_factor, time_earth, time_spaceship;
    double average_human_lifespan = 75.0;  // Average human lifespan in years
    double generations;

    // Prompt user for the name of the star
    printf("Please enter the name of your destination point: ");
    scanf("%s", starName);

    // Prompt user for the departure point
    printf("Please enter your current location (departure point): ");
    scanf("%s", departure_point);

    // Prompt user for the name of the spaceship
    printf("Please enter the name of your spaceship: ");
    scanf("%s", spaceship_name);

    // Prompt user for the distance to the star in light years
    printf("Please enter the distance from your departure point to your destination star in light years: ");
    scanf("%lf", &distance);
    
    // Check if distance is a positive number
    if (distance <= 0) {
        printf("Invalid input. The distance to the star must be a positive number.\n");
        return 1;  // Exit program with error code 1
    }

    // Prompt user for the speed of the spaceship as a fraction of the speed of light (0 < speed < 1)
    printf("Please enter the speed of your spaceship as a fraction of the speed of light (0 < speed < 1): ");
    scanf("%lf", &speed);
    
    // Check if speed is within valid range
    if (speed <= 0 || speed >= 1) {
        printf("Invalid input. The speed must be a fraction of the speed of light (0 < speed < 1).\n");
        return 1;  // Exit program with error code 1
    }

    // Calculate Lorentz factor
    lorentz_factor = 1 / sqrt(1 - speed * speed);

    // Calculate time from Earth observer's perspective
    time_earth = distance / speed;
    
    // Calculate time from spaceship traveler's perspective
    time_spaceship = time_earth / lorentz_factor;

    // Calculate how many generations would live and die on Earth during this journey
    generations = time_earth / average_human_lifespan;

    // Print results
    printf("\nFrom an observer's perspective on %s, it will take approximately %.2f years for %s to reach %s.\n", departure_point, time_earth, spaceship_name, starName);
    
     printf("However, due to the effects of special relativity, a traveler on %s will feel as though %.2f years have passed.\n", spaceship_name, time_spaceship);
     
     printf("This means that all passengers on %s will age by approximately %.2f years during this journey.\n", spaceship_name, time_spaceship);
     
     printf("Meanwhile, people on %s will age by approximately %.2f years.\n", departure_point, time_earth);
     
     printf("During this journey, approximately %.2f generations of humans would live and die back on %s.\n", generations, departure_point);

     return 0;
}
