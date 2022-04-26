package belajar_golang_logging

import (
	"testing"

	"github.com/sirupsen/logrus"
)

func TestField(t *testing.T) {
	logger := logrus.New()
	logger.SetFormatter(&logrus.JSONFormatter{})

	logger.WithField("username", "TobiAlbertino").
		Info("Hello world")

	logger.WithField("username", "TobiAlbertino").
		WithField("name", "Tobi Albertino").
		Info("Hello World")
}

func TestFields(t *testing.T) {
	logger := logrus.New()
	logger.SetFormatter(&logrus.JSONFormatter{})

	logger.WithFields(logrus.Fields{
		"username": "tobialbertino",
		"name":     "Tobi Albertino",
	}).Info("Hello World")
}
