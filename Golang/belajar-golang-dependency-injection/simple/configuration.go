package simple

type Configuraiton struct {
	Name string
}

type Application struct {
	*Configuraiton
}

func NewApplication() *Application {
	return &Application{
		Configuraiton: &Configuraiton{
			Name: "ProgrammerZamanNow",
		},
	}
}
