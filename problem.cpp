#include<iostream>
#include<chrono>

using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;

int main(){

  const unsigned long num = 600851475143;
  unsigned long temp_num = num;
  unsigned long greatest_factor = 0;
  unsigned long counter = 3;

  const auto before = high_resolution_clock::now();

  while (counter * counter <= temp_num) {
    if (temp_num % counter == 0) {
      temp_num = temp_num / counter;
      greatest_factor = counter;
    } else {
      counter += 2;
    }
  }
  const auto after = high_resolution_clock::now();

  if (temp_num > greatest_factor) {
  greatest_factor = temp_num;
  }

  std::chrono::duration<double> execute_time = after - before;
  std::cout << greatest_factor << std::endl << "Execution time: " << execute_time.count() << " seconds" << std::endl;
}
