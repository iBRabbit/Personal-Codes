let mahasiswa = {
    nama : 'Felix',
    energy : 100,
    makan : function (porsi) {
        this.energy += porsi;
        console.log("Energy tambah", porsi);
    }
}

function Mahasiswa(nama, energy) {
    let mahasiswa = {};
    mahasiswa.nama = nama;
    mahasiswa.energy = energy;

    mahasiswa.makan = function (porsi) {
        this.energy += porsi;
        console.log(`Halo $(this.nama) selamat makan`);
    }

    return mahasiswa;
}

let mahasiswa2 = Mahasiswa("Udin", 10);

function MahasiswaBaru(nama, energy) {
    this.nama = nama;
    this.energy = energy;

    this.makan = function (porsi) {
            this.energy += porsi;
            console.log(`Halo $(this.nama) selamat makan`);
    }

}
let mahasiswa3 = MahasiswaBaru("Emon", 50);

