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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/cpufreq.h>
#include <linux/retain_cpu_policy.h>

struct cpufreq_user_policy user_policy[CONFIG_NR_CPUS];

void retain_cpu_policy(struct cpufreq_policy *policy)
{
	if(policy != NULL){
		user_policy[policy->cpu].min = policy->min;
		user_policy[policy->cpu].max = policy->max;
		user_policy[policy->cpu].governor = policy->governor;
	}
}

bool retained_cpu_policy(int cpu)
{
	return (user_policy[cpu].min != NULL && user_policy[cpu].max != NULL && user_policy[cpu].governor != NULL);
}

unsigned int get_retained_min_cpu_freq(int cpu)
{
	return user_policy[cpu].min;
}

unsigned int get_retained_max_cpu_freq(int cpu)
{
	return user_policy[cpu].max;
}

struct cpufreq_governor* get_retained_governor(int cpu)
{
	return user_policy[cpu].governor;
}

int retain_cpu_policy_init(void)
{
	printk("retain_cpu_policy: Emman was here.\n");
	return 0;
}

module_init(retain_cpu_policy_init);
MODULE_AUTHOR("Emmanuel Utomi <emmanuelutomi@gmail.com>");
