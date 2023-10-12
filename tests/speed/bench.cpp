#include <iostream>
#include <chrono>
#include <tuple>
#include <vector>
#include <limits>

struct Timer
{
  std::chrono::high_resolution_clock::time_point begin, end;
  void start() { begin = std::chrono::high_resolution_clock::now(); }
  void finish() { end = std::chrono::high_resolution_clock::now(); }
};

std::tuple<double, double, double> tensor1();
std::tuple<double, double, double> tensor2();
std::tuple<double, double, double> tensor3();
std::tuple<double, double, double> tensor4();
std::tuple<double, double, double> tensor5();
std::tuple<double, double, double> tensor6();
std::tuple<double, double, double> tensor7();
std::tuple<double, double, double> tensor8();
std::tuple<double, double, double> tensor9();

std::tuple<double, double, double> ctran1();
std::tuple<double, double, double> ctran2();
std::tuple<double, double, double> ctran3();
std::tuple<double, double, double> ctran4();
std::tuple<double, double, double> ctran5();
std::tuple<double, double, double> ctran6();
std::tuple<double, double, double> ctran7();
std::tuple<double, double, double> ctran8();
std::tuple<double, double, double> ctran9();

std::tuple<int64_t, int64_t>
run_test(const size_t &num_trials,
         std::tuple<double, double, double> (*test_function)())
{
  int64_t min_t(std::numeric_limits<int64_t>::max()), max_t(0);
  std::tuple<double, double, double> sum(0, 0, 0);
  for(size_t trial = 0; trial < num_trials; ++trial)
    {
      Timer timer;
      timer.start();
      auto y = test_function();
      std::get<0>(sum) += std::get<0>(y);
      std::get<1>(sum) += std::get<1>(y);
      std::get<2>(sum) += std::get<2>(y);
      timer.finish();
      auto t((std::chrono::duration_cast<std::chrono::milliseconds>(
                timer.end - timer.begin))
               .count());
      std::cout << "trial: " << trial << " " << t << "\n";
      min_t = std::min(min_t, t);
      max_t = std::max(max_t, t);
    }
  std::cout << "sum: " << std::get<0>(sum) << " " << std::get<1>(sum) << " "
            << std::get<2>(sum) << " " << min_t << " " << max_t << " "
            << "\n";
  return std::make_tuple(min_t, max_t);
}

int main(int argv, char *argc[])
{
  int num_trials(10);
  if(argv > 1)
    {
      num_trials = std::stoi(argc[1]);
    }
  std::vector<std::tuple<int64_t, int64_t>> tensor_times, ctran_times;

  // Warm up before starting real run.
  run_test(num_trials, tensor1);
  run_test(num_trials, tensor1);
  run_test(num_trials, tensor1);

  tensor_times.emplace_back(run_test(num_trials, tensor1));
  tensor_times.emplace_back(run_test(num_trials, tensor2));
  tensor_times.emplace_back(run_test(num_trials, tensor3));
  tensor_times.emplace_back(run_test(num_trials, tensor4));
  tensor_times.emplace_back(run_test(num_trials, tensor5));
  tensor_times.emplace_back(run_test(num_trials, tensor6));
  tensor_times.emplace_back(run_test(num_trials, tensor7));
  tensor_times.emplace_back(run_test(num_trials, tensor8));
  tensor_times.emplace_back(run_test(num_trials, tensor9));

  ctran_times.emplace_back(run_test(num_trials, ctran1));
  ctran_times.emplace_back(run_test(num_trials, ctran2));
  ctran_times.emplace_back(run_test(num_trials, ctran3));
  ctran_times.emplace_back(run_test(num_trials, ctran4));
  ctran_times.emplace_back(run_test(num_trials, ctran5));
  ctran_times.emplace_back(run_test(num_trials, ctran6));
  ctran_times.emplace_back(run_test(num_trials, ctran7));
  ctran_times.emplace_back(run_test(num_trials, ctran8));
  ctran_times.emplace_back(run_test(num_trials, ctran9));

  for(size_t ii = 0; ii < tensor_times.size(); ++ii)
    {
      std::cout << ii << " " << std::get<0>(tensor_times[ii]) << " "
                << std::get<1>(tensor_times[ii]) << " "
                << std::get<0>(ctran_times[ii]) << " "
                << std::get<1>(ctran_times[ii]) << " "
                << "\n";
    }
}
