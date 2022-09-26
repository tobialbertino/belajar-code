sudo adduser dicoding
# Username: dicoding
# Full Name: Dicoding Indonesia

sudo apt install openssh-server
sudo service ssh status
ssh-keygen

ssh-copy-id -i ~/.ssh/id_rsa.pub dicoding@LAPTOP-VHBSQEPE

sudo mkdir /home/dicoding/.ssh/
sudo chmod 0700 /home/dicoding/.ssh/
sudo -- sh -c "echo 'ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQD8YaflkSd0EZ2Xid4EttI8fEvaqof9wKfNOUhC3zt0c1Pf778jbJkmlktxUTh6zCfkBriachcUFHmQvybA3ePD/FrNVWZmYtuLZLhQkywQagMd5bXKxmkvwRXj6O0o278ORlxTzWW0FZGNywlkCCw/3PyCbsbYIVSUczbiGJbSrNhtNmbn8nbUYr7OJg8VomLbGCydTlr7+gZMkdHxKjFgvnS1xEyCoyIvmZG+YSKprZEfMwEyWOvufVP5CmyB0jkxzZNpz5J3vVxVLtB3AE2rvdxLQSPjlI7F5bEj3dL5o61f5sxvrNU2UrIVk1KuY9BX/x/7+uk+PvBwch3MGmO11WsQAnA62a5UvNcqDTWDlW8qfaGjslnret/4aRfjnY8yD5qCxCVL9H5iH08BdmSvpmuvDbpSSD+Pw0uWvVM2ej9tXkhU2dU1jxJBErpd0DABSRv7pDCwhQqZ4tciAQMZtmskd1BgLGgUYywmnS512Sj/3KnOcx//eQ62maaZeFM= tobi@LAPTOP-VHBSQEPE' > /home/dicoding/.ssh/authorized_keys"
sudo chown -R dicoding:dicoding /home/dicoding/.ssh/

sudo chmod ugo+rwx /etc/ssh/sshd_config

# // list user
cat /etc/passwd > daftar-user.txt

sudo journalctl -u ssh.service > ssh-log.txt

# alternative wsl
sudo service rsyslog start
service rsyslog start
cat /var/log/auth.log > ssh-log.txt

sudo journalctl -b -u ssh -o json-pretty > ssh-log.json