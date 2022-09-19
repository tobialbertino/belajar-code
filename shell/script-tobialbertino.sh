#!/bin/bash

# get memory total in MB,error when run in script file 
function get_memory_total_in_MB() {
  # store output shell to variable
  memory_total_KB=$(cat /proc/meminfo | grep 'MemTotal' | grep -o '[[:digit:]]\+')
  memory_total_MB=$((memory_total_KB/1000))
  echo memory_total : $memory_total_MB MB
  
}

# get disk free human readable, Powers of 1024, only column source,used
function get_disk_free_gb() {
  df -h --output=source,used
}

# get disk free only column source,pcent
function get_disk_pcent() {
  df -h -x tmpfs --output=source,pcent
}

function sleep_minute() {
  sleep $(($1*60))
}

# true sebagai penanda bahwa perulangan ini berlangsung terus
while true
do
  # kriteria 1 Menampilkan ukuran memory pada sistem dalam satuan megabytes
  echo "--> get memory total in 'MB'"
  get_memory_total_in_MB
  echo ""
  sleep 3

  # kriteria 2 Menampilkan penggunaan ruang disk pada filesystem dalam satuan gigabytes
  echo "--> get disk used in 'GB',"
  get_disk_free_gb
  echo ""
  sleep 3

  # kriteria 3  Menampilkan penggunaan ruang disk pada filesystem hanya untuk kolom Filesystem dan Use%
  echo "--> get disk usage in percent"
  get_disk_pcent
  echo ""
  sleep_minute 1

done

# touch script-tobialbertino.sh 
# touch history-tobialbertino.txt