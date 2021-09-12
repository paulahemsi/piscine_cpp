#!/bin/bash

cat old_log.txt | cut -d ' ' -f2 > old_log
cat new_log.txt | cut -d ' ' -f2 > new_log
diff old_log new_log > diff
