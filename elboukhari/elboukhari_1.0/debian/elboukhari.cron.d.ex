#
# Regular cron jobs for the elboukhari package
#
0 4	* * *	root	[ -x /usr/bin/elboukhari_maintenance ] && /usr/bin/elboukhari_maintenance
