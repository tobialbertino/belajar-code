package belajar_golang_gorm

import "time"

type User struct {
	ID          string    `gorm:"column:id;primaryKey;<-:create"`
	Password    string    `gorm:"column:password"`
	Name        Name      `gorm:"embedded"`
	CreatedAt   time.Time `gorm:"column:created_at;autoCreateTime:true;<-:create"`
	UpdatedAt   time.Time `gorm:"column:updated_at;autoCreateTime:true;autoUpdateTime:true"`
	Information string    `gorm:"-"`
	Wallet      Wallet    `gorm:"foreignKey:user_id;references:id"`
}

func (u User) TableName() string {
	return "users"
}

type Name struct {
	FirstName  string `gorm:"column:first_name"`
	MiddleName string `gorm:"column:middle_name"`
	LastName   string `gorm:"column:last_name"`
}

type UserLog struct {
	ID        int    `gorm:"column:id;primaryKey;autoIncrement"`
	UserId    string `gorm:"column:user_id"`
	Action    string `gorm:"column:action"`
	CreatedAt int64  `gorm:"column:created_at;autoCreateTime:milli"`
	UpdatedAt int64  `gorm:"column:updated_at;autoCreateTime:milli;autoUpdateTime:milli"`
}

func (l *UserLog) TableName() string {
	return "user_logs"
}
