/*
 * Copyright (c) 2014, Emmanuel Utomi <emmanuelutomi@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/cpufreq.h>

#ifndef LINUX_RETAIN_CPUPOLICY_H
#define LINUX_RETAIN_CPUPOLICY_H

struct cpufreq_user_policy {
	unsigned int min;
	unsigned int max;
	struct cpufreq_governor* governor;
};

#ifdef CONFIG_CPU_FREQ_RETAIN_POLICY
void retain_cpu_policy(struct cpufreq_policy *policy);
bool retained_cpu_policy(int cpu);
unsigned int get_retained_min_cpu_freq(int cpu);
unsigned int get_retained_max_cpu_freq(int cpu);
struct cpufreq_governor* get_retained_governor(int cpu);
#else
static inline void retain_cpu_policy(struct cpufreq_policy *policy) {}
static inline bool retained_cpu_policy(int cpu) { return false; }
static inline unsigned int get_retained_min_cpu_freq(int cpu) { return 0; }
static inline unsigned int get_retained_max_cpu_freq(int cpu) { return 0; }
static inline struct cpufreq_governor* get_retained_governor(int cpu) { return NULL; }
#endif

#endif
