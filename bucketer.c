#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

// Function to calculate SoH for a given present capacity and rated capacity
float calculateSoH(int presentCapacity, int ratedCapacity) {
    return ((float)presentCapacity / ratedCapacity) * 100;
}

// Function to classify batteries by State-of-Health (SoH) and display information
struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  
  struct CountsBySoH counts = {0, 0, 0};
  // Rated capacity of a new battery
  int ratedCapacity = 120;
  printf("Battery Information:\n");
  for (int i = 0; i < nBatteries; ++i) {
  // Compute State-of-Health (SoH)
  float soh = (float)presentCapacities[i] / ratedCapacity * 100;
  // Display SoH for each battery
  printf("Battery %d: SoH = %.2f%%\n", i + 1, soh);
  // Classify batteries based on SoH
    if (soh > 80) {
      counts.healthy++;
    } else if (soh >= 62) {
      counts.exchange++;
    } else {
      counts.failed++;
    }
  }

  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  //assert(counts.healthy == 2);
  //assert(counts.exchange == 3);
  //assert(counts.failed == 1);
  printf("\nCounts: Healthy = %d, Exchange = %d, Failed = %d\n", counts.healthy, counts.exchange, counts.failed);
  printf("Done counting :)\n");
  
  //All batteries failed
  const int presentCapacities3[] = {50, 40, 30, 20, 10};
  const int numberOfBatteries3 = sizeof(presentCapacities3) / sizeof(presentCapacities3[0]);
  struct CountsBySoH counts3 = countBatteriesByHealth(presentCapacities3, numberOfBatteries3);
  printf("\nCounts: Healthy = %d, Exchange = %d, Failed = %d\n", counts3.healthy, counts3.exchange, counts3.failed);
  
  //empty battery array
  const int presentCapacities4[] = {};
  const int numberOfBatteries4 = 0;
  struct CountsBySoH counts4 = countBatteriesByHealth(presentCapacities4, numberOfBatteries4);
  printf("\nCounts: Healthy = %d, Exchange = %d, Failed = %d\n", counts4.healthy, counts4.exchange, counts4.failed);
  
  // Boundary condition - maximum rated capacity
  const int presentCapacities5[] = {120, 120, 120, 120};
  const int numberOfBatteries5 = sizeof(presentCapacities5) / sizeof(presentCapacities5[0]);
  struct CountsBySoH counts5 = countBatteriesByHealth(presentCapacities5, numberOfBatteries5);
  printf("\nCounts: Healthy = %d, Exchange = %d, Failed = %d\n", counts5.healthy, counts5.exchange, counts5.failed);
  
  // Boundary condition - all batteries with minimum rated capacity
  const int presentCapacities6[] = {1, 1, 1, 1};
  const int numberOfBatteries6 = sizeof(presentCapacities6) / sizeof(presentCapacities6[0]);
  struct CountsBySoH counts6 = countBatteriesByHealth(presentCapacities6, numberOfBatteries6);
  printf("\nCounts: Healthy = %d, Exchange = %d, Failed = %d\n", counts6.healthy, counts6.exchange, counts6.failed);
  

  
}

int main() {
  testBucketingByHealth();
  return 0;
}
