#include <rt/latency_tracker.h>
#include <spdlog/spdlog.h>

namespace rt {
void LatencyTracker::RecordValue(double v) noexcept {
  if (v < min_) {
    min_ = v;
  }

  if (v > max_) {
    max_ = v;
  }

  ++count_;
  mean_ = mean_ * (count_ - 1) / count_ + v / count_;

  // TODO: histogram
}

void LatencyTracker::DumpToLogger() const {
  SPDLOG_DEBUG("min: {:.4f} | mean: {:.4f} | max: {:.4f} | count: {}", min_, mean_, max_, count_);
}
}  // namespace rt
