from KaryaSeni import KaryaSeni
from Film import Film
from FilmAnimasi import FilmAnimasi


# =====================================================
# FUNCTION INPUT INTEGER
# =====================================================

# Function untuk menerima input berupa bilangan bulat.
# Jika input bukan bilangan bulat, user diminta mengulang.
def inputInteger(pesan):
    while True:
        try:
            nilai = int(input(pesan))
            return nilai
        except ValueError:
            print("Error: input harus berupa angka.")


# =====================================================
# FUNCTION INPUT STRING
# =====================================================

# Function untuk menerima input berupa string.
# Input yang kosong tidak diperbolehkan.
def inputString(pesan):
    while True:
        nilai = input(pesan).strip()

        if nilai:
            return nilai

        print("Error: input tidak boleh kosong.")


# =====================================================
# FUNCTION INPUT INTEGER RANGE
# =====================================================

# Function untuk menerima bilangan bulat yang harus
# berada di antara nilai minimum dan maksimum.
def inputIntegerRange(pesan, minimum, maksimum):
    while True:
        nilai = inputInteger(pesan)

        if minimum <= nilai <= maksimum:
            return nilai

        print(
            f"Error: nilai harus berada di antara "
            f"{minimum} dan {maksimum}."
        )


# =====================================================
# FUNCTION CEK ID
# =====================================================

# Function untuk mengecek apakah ID sudah digunakan
# oleh object film yang terdapat di dalam list.
def idSudahAda(daftarFilm, id):
    for film in daftarFilm:
        if film.getId() == id:
            return True

    return False


# =====================================================
# FUNCTION INPUT ID UNIK
# =====================================================

# Function untuk menerima ID baru.
# ID harus diisi dan tidak boleh sama dengan ID
# yang sudah dimiliki oleh object lain.
def inputIdUnik(daftarFilm):
    while True:
        id = inputString("ID              : ")

        if not idSudahAda(daftarFilm, id):
            return id

        print("Error: ID sudah digunakan. Silakan gunakan ID lain.")


# =====================================================
# PROSEDUR TAMBAH DATA
# =====================================================

# Prosedur untuk menerima input data FilmAnimasi
# kemudian membuat object baru dan memasukkannya
# ke dalam list daftarFilm.
def tambahFilm(daftarFilm):
    print("\n===== TAMBAH FILM ANIMASI =====")

    # Atribut KaryaSeni
    id = inputIdUnik(daftarFilm)
    judul = inputString("Judul           : ")
    tahunRilis = inputIntegerRange(
        "Tahun Rilis     : ",
        1900,
        2100
    )
    pencipta = inputString("Pencipta        : ")

    # Atribut Film
    genre = inputString("Genre           : ")
    durasi = inputIntegerRange(
        "Durasi (menit)  : ",
        0,
        600
    )
    harga = inputIntegerRange(
        "Harga           : Rp",
        0,
        1000000
    )

    # Atribut FilmAnimasi
    studioAnimasi = inputString("Studio Animasi  : ")
    teknikAnimasi = inputString("Teknik Animasi  : ")

    # Meminta jumlah pengisi suara yang akan dimasukkan.
    jumlahPengisiSuara = inputIntegerRange(
        "Jumlah Pengisi Suara: ",
        1,
        100
    )

    pengisiSuara = []

    # Memasukkan setiap nama pengisi suara ke dalam list.
    for i in range(jumlahPengisiSuara):
        nama = inputString(
            f"Pengisi Suara {i + 1}: "
        )

        pengisiSuara.append(nama)

    # Membuat object baru
    filmBaru = FilmAnimasi(
        id,
        judul,
        tahunRilis,
        pencipta,
        genre,
        durasi,
        harga,
        studioAnimasi,
        teknikAnimasi,
        pengisiSuara
    )

    # Memasukkan object ke list
    daftarFilm.append(filmBaru)

    print("\nData film berhasil ditambahkan!")


# =====================================================
# PROSEDUR MEMBUAT GARIS TABEL
# =====================================================

# Prosedur untuk membuat garis horizontal tabel.
# Panjang setiap kolom disesuaikan dengan lebar
# kolom yang telah dihitung sebelumnya.
def buatGaris(lebarKolom):
    print("+", end="")

    for lebar in lebarKolom:
        print("-" * (lebar + 2) + "+", end="")

    print()


# =====================================================
# PROSEDUR TAMPILKAN DATA
# =====================================================

# Prosedur untuk menampilkan seluruh object FilmAnimasi dalam satu tabel.
# Tabel mencakup seluruh atribut yang berasal dari:
# 1. KaryaSeni
# 2. Film
# 3. FilmAnimasi
# Lebar setiap kolom dibuat dinamis mengikuti data
# terpanjang pada kolom tersebut.
def tampilkanSemuaFilm(daftarFilm):
    # Jika list kosong, tidak ada data yang ditampilkan.
    if not daftarFilm:
        print("\nBelum ada data film.")
        return

    # Header tabel berisi seluruh atribut dari ketiga class.
    header = [
        "ID",
        "Judul",
        "Tahun Rilis",
        "Pencipta",
        "Genre",
        "Durasi",
        "Harga",
        "Studio Animasi",
        "Teknik Animasi",
        "Pengisi Suara"
    ]

    data = []

    # Mengambil seluruh data dari setiap object
    # untuk dimasukkan ke dalam tabel.
    for film in daftarFilm:
        # List pengisi suara digabungkan menjadi satu string agar dapat ditampilkan dalam satu cell.
        daftarVoiceActor = ", ".join(
            film.getPengisiSuara()
        )

        baris = [
            film.getId(),
            film.getJudul(),
            str(film.getTahunRilis()),
            film.getPencipta(),
            film.getGenre(),
            str(film.getDurasi()) + " menit",
            "Rp" + str(film.getHarga()),
            film.getStudioAnimasi(),
            film.getTeknikAnimasi(),
            daftarVoiceActor
        ]

        data.append(baris)

    # Menentukan lebar setiap kolom
    # Lebar awal setiap kolom mengikuti panjang header.
    lebarKolom = []

    for i in range(len(header)):
        lebar = len(header[i])

        # Membandingkan panjang header dengan seluruh
        # data pada kolom yang sama.
        for baris in data:
            if len(baris[i]) > lebar:
                lebar = len(baris[i])

        lebarKolom.append(lebar)

    # Menampilkan Tabel
    print("\n")
    print(
        "========================================== "
        "DAFTAR FILM ANIMASI "
        "=========================================="
    )

    # Garis bagian atas tabel.
    buatGaris(lebarKolom)

    # Menampilkan header tabel.
    print("|", end="")

    for i in range(len(header)):
        print(
            f" {header[i]:<{lebarKolom[i]}} |",
            end=""
        )

    print()

    # Garis pemisah antara header dan data.
    buatGaris(lebarKolom)

    # Menampilkan seluruh data object.
    for baris in data:
        print("|", end="")

        for i in range(len(baris)):
            print(
                f" {baris[i]:<{lebarKolom[i]}} |",
                end=""
            )

        print()

    buatGaris(lebarKolom)


# =====================================================
# MAIN
# =====================================================

if __name__ == "__main__":

    # =================================================
    # 5 OBJECT AWAL
    # =================================================

    film1 = FilmAnimasi(
        "F001",
        "Demon Slayer: Mugen Train",
        2020,
        "Koyoharu Gotouge",
        "Action, Fantasy",
        117,
        50000,
        "Ufotable",
        "2D Digital",
        [
            "Natsuki Hanae",
            "Akari Kito",
            "Satoshi Hino"
        ]
    )

    film2 = FilmAnimasi(
        "F002",
        "Jujutsu Kaisen 0",
        2021,
        "Gege Akutami",
        "Action, Fantasy",
        105,
        45000,
        "MAPPA",
        "2D Digital",
        [
            "Megumi Ogata",
            "Kana Hanazawa",
            "Yuichi Nakamura"
        ]
    )

    film3 = FilmAnimasi(
        "F003",
        "Your Name",
        2016,
        "Makoto Shinkai",
        "Romance, Fantasy",
        106,
        45000,
        "CoMix Wave Films",
        "2D Digital",
        [
            "Ryunosuke Kamiki",
            "Mone Kamishiraishi"
        ]
    )

    film4 = FilmAnimasi(
        "F004",
        "One Piece Film: Red",
        2022,
        "Eiichiro Oda",
        "Action, Advanture",
        115,
        50000,
        "Toei Animation",
        "2D Digital",
        [
            "Kaori Nazuka",
            "Suichi Ikeda",
            "Mayumi Tanaka"
        ]
    )

    film5 = FilmAnimasi(
        "F005",
        "The Boy and the Heron",
        2023,
        "Hayao Miyazaki",
        "Fantasy, Adventure",
        124,
        55000,
        "Studio Ghibli",
        "2D Hand-Drawn",
        [
            "Soma Santoki",
            "Masaki Suda",
            "Takuya Kimura"
        ]
    )

    # List yang digunakan untuk menyimpan seluruh object
    # FilmAnimasi, termasuk lima object awal dan object
    # baru yang ditambahkan oleh user.
    daftarFilm = [
        film1,
        film2,
        film3,
        film4,
        film5
    ]

    # =================================================
    # MENU
    # =================================================

    # Program terus menampilkan menu sampai user
    # memilih pilihan 0 untuk keluar.
    while True:
        print("\n==============================")
        print("      MENU FILM ANIMASI       ")
        print("==============================")
        print("1. Tambah Data")
        print("2. Tampilkan Data")
        print("0. Keluar")

        pilihan = inputInteger("Pilihan: ")

        if pilihan == 1:
            tambahFilm(daftarFilm)

        elif pilihan == 2:
            tampilkanSemuaFilm(daftarFilm)

        elif pilihan == 0:
            print("\nProgram selesai.")
            break

        else:
            print("Error: pilihan menu tidak tersedia.")