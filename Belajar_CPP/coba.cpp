db.mahasiswa.insertMany([
    { Nama: "Alpha", Jurusan: "Ilkom", Daerah: "Jabar", Tinggal: "Kost", Income: 1000000 },
    { Nama: "Beta", Jurusan: "Ilkom", Daerah: "Jabar", Tinggal: "Kontrak", Income: 500000 },
    { Nama: "Carlie", Jurusan: "Statik", Daerah: "DKI", Tinggal: "Kontrak", Income: 100000 },
    { Nama: "David", Jurusan: "Statik", Daerah: "DKI", Tinggal: "Kost", Income: 200000 },
    { Nama: "Echo", Jurusan: "Statik", Daerah: "Jateng", Tinggal: "Kontrak", Income: 50000 },
    { Nama: "Foxfot", Jurusan: "Aktuaria", Daerah: "Sulses", Tinggal: "Rumah", Income: 10000 },
    { Nama: "German", Jurusan: "Aktuaria", Daerah: "Sumut", Tinggal: "Rumah", Income: 5000000 },
    { Nama: "Holand", Jurusan: "Aktuaria", Daerah: "Kalbar", Tinggal: "Kost", Income: 30000 },
    { Nama: "India", Jurusan: "Fisika", Daerah: "Kaltim", Tinggal: "Kost", Income: 20000 },
    
])
    
db.getCollection('mahasiswa').find({}) 

db.mahasiswa.find(
    {
        $and: [
            {Income :{$gte:100000}}, {Tinggal :"Kost"}
        ]
    }
)