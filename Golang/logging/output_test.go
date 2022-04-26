package belajar_golang_logging

import (
	"os"
	"testing"

	"github.com/sirupsen/logrus"
)

func Test(t *testing.T) {
	logger := logrus.New()

	file, _ := os.OpenFile("application.log", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0666)
	logger.SetOutput(file)

	logger.Info("Hello logging")
	logger.Warn("Hello logging")
	logger.Error("Hello logging")
}
