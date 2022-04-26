package belajar_golang_logging

import (
	"testing"

	"github.com/sirupsen/logrus"
)

func TestFomatter(t *testing.T) {
	logger := logrus.New()
	logger.SetFormatter(&logrus.JSONFormatter{})

	logger.Info("Hello logger")
	logger.Warn("Hello logger")
	logger.Error("Hello logger")
}
