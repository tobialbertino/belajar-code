#!/bin/bash
# Fungsi belum dicoba karena menggunakan wsl, tidak ada systemd dan journalctl kosong 

function hapus_log_10MB() {
# menampilkan informasi penggunaan disk
echo "--> disc usage information 'journalctl'"
sudo journalctl --disk-usage
echo ""
sleep 5

# Lalu, menghapus journalctl log hingga ruang disk yang digunakan untuk log berada di bawah 10 MB.
echo "--> vacuum journalctl 10MB"
sudo journalctl --vacuum-size=10M
echo ""
sleep 5

# Kemudian, menampilkan kembali informasi penggunaan disk dari semua berkas journalctl, baik yang aktif maupun yang diarsipkan.
echo "--> disc usage information 'journalctl'"
sudo journalctl --disk-usage
echo ""
sleep 5
}

while true
do
  hapus_log_10MB
done