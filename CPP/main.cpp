#include <bits/stdc++.h>

using namespace std;

// =========================
// INCLUDE CLASS
// =========================

// KaryaSeni merupakan base class.
#include "KaryaSeni.cpp"

// Film merupakan turunan dari KaryaSeni.
#include "Film.cpp"

// FilmAnimasi merupakan turunan dari Film.
#include "FilmAnimasi.cpp"

// =====================================================
// FUNCTION INPUT INTEGER
// =====================================================

// Function ini digunakan untuk memastikan user memasukkan nilai berupa integer.
// Jika input bukan angka, user akan diminta mengulang.
int inputInteger(string pesan)
{
    int nilai;

    while (true)
    {
        cout << pesan;
        cin >> nilai;

        // Mengecek apakah input gagal dibaca sebagai integer.
        if (cin.fail())
        {
            cout << "Error: input harus berupa angka.\n";

            // Mengembalikan kondisi cin seperti semula.
            cin.clear();

            // Membuang input yang salah dari buffer.
            cin.ignore(1000, '\n');
        }
        else
        {
            // Jika input valid, buang Enter yang tersisa.
            cin.ignore(1000, '\n');

            return nilai;
        }
    }
}

// =====================================================
// FUNCTION INPUT STRING
// =====================================================

// Function ini digunakan untuk meminta input string yang tidak boleh kosong.
string inputString(string pesan)
{
    string nilai;

    while (true)
    {
        cout << pesan;
        getline(cin, nilai);

        if (nilai.empty())
        {
            cout << "Error: data tidak boleh kosong.\n";
        }
        else
        {
            return nilai;
        }
    }
}

// =====================================================
// CEK ID
// =====================================================

// Mengecek apakah ID sudah digunakan oleh object lain.
// Return:
// true  -> ID sudah digunakan
// false -> ID belum digunakan
bool idSudahAda(const vector<FilmAnimasi> &daftarFilm, string id)
{
    for (const FilmAnimasi &film : daftarFilm)
    {
        if (film.getId() == id)
        {
            return true;
        }
    }

    return false;
}

// =====================================================
// FUNCTION INPUT ID UNIK
// =====================================================

// Function ini meminta ID sampai mendapatkan ID yang tidak digunakan oleh object lain.
string inputIdUnik(const vector<FilmAnimasi> &daftarFilm)
{
    string id;

    while (true)
    {
        id = inputString("ID              : ");

        if (idSudahAda(daftarFilm, id))
        {
            cout << "Error: ID tersebut sudah digunakan.\n";
        }
        else
        {
            return id;
        }
    }
}

// =====================================================
// FUNCTION INPUT INTEGER DENGAN RANGE
// =====================================================

// Function ini memastikan input berupa integer dan berada dalam rentang minimum sampai maksimum.
int inputIntegerRange(string pesan, int minimum, int maksimum)
{
    int nilai;

    while (true)
    {
        nilai = inputInteger(pesan);

        if (nilai < minimum || nilai > maksimum)
        {
            cout << "Error: nilai harus berada di antara " << minimum << " dan " << maksimum << ".\n";
        }
        else
        {
            return nilai;
        }
    }
}

// =====================================================
// PROSEDUR TAMBAH DATA
// =====================================================

// Prosedur ini digunakan untuk membuat object FilmAnimasi
// baru berdasarkan input user, kemudian memasukkannya
// ke dalam vector daftarFilm.
void tambahFilm(vector<FilmAnimasi> &daftarFilm)
{
    // =========================
    // VARIABLE INPUT
    // =========================

    string id;
    string judul;
    int tahunRilis;
    string pencipta;

    string genre;
    int durasi;
    int harga;

    string studioAnimasi;
    string teknikAnimasi;

    vector<string> pengisiSuara;

    // =========================
    // INPUT DATA KARYASENI
    // =========================

    cout << "\n===== TAMBAH FILM ANIMASI =====\n";

    id = inputIdUnik(daftarFilm);

    judul = inputString("Judul           : ");

    tahunRilis = inputIntegerRange("Tahun Rilis     : ", 1900, 2100);

    pencipta = inputString("Pencipta        : ");

    // =========================
    // INPUT DATA FILM
    // =========================

    genre = inputString("Genre           : ");

    durasi = inputIntegerRange("Durasi (menit)  : ", 0, 600);

    harga = inputIntegerRange("Harga           : Rp", 0, 1000000);

    // =========================
    // INPUT DATA FILMANIMASI
    // =========================

    studioAnimasi = inputString("Studio Animasi  : ");

    teknikAnimasi = inputString("Teknik Animasi  : ");

    // =========================
    // INPUT PENGISI SUARA
    // =========================

    int jumlahPengisiSuara;

    jumlahPengisiSuara = inputIntegerRange("Jumlah Pengisi Suara : ", 1, 20);

    for (int i = 0; i < jumlahPengisiSuara; i++)
    {
        string nama;

        nama = inputString("Pengisi Suara " + to_string(i + 1) + " : ");

        pengisiSuara.push_back(nama);
    }

    // =========================
    // MEMBUAT OBJECT
    // =========================

    FilmAnimasi filmBaru(
        id,
        judul,
        tahunRilis,
        pencipta,
        genre,
        durasi,
        harga,
        studioAnimasi,
        teknikAnimasi,
        pengisiSuara);

    // =========================
    // MENAMBAHKAN OBJECT
    // =========================

    daftarFilm.push_back(filmBaru);

    cout << "\nFilm berhasil ditambahkan!\n";
}

// =========================
// PROSEDUR PEMBUAT GARIS
// =========================

// Membuat garis horizontal berdasarkan lebar setiap kolom.
void buatGaris(const vector<int> &lebarKolom)
{
    cout << "+";

    for (int i = 0; i < lebarKolom.size(); i++)
    {
        cout << string(lebarKolom[i] + 2, '-') << "+";
    }

    cout << endl;
}

// =========================
// PROSEDUR TAMPILKAN DATA
// =========================

// Prosedur ini menampilkan seluruh data FilmAnimasi dalam satu tabel.
// Data yang ditampilkan mencakup atribut dari KaryaSeni, Film, dan FilmAnimasi.
void tampilkanSemuaFilm(const vector<FilmAnimasi> &daftarFilm)
{
    // Jika belum ada data
    if (daftarFilm.empty())
    {
        cout << "\nBelum ada data film.\n";
        return;
    }

    // =========================
    // MENYIAPKAN DATA TABEL
    // =========================

    vector<vector<string>> data;

    for (int i = 0; i < daftarFilm.size(); i++)
    {
        vector<string> baris;

        // Atribut KaryaSeni
        baris.push_back(daftarFilm[i].getId());
        baris.push_back(daftarFilm[i].getJudul());
        baris.push_back(to_string(daftarFilm[i].getTahunRilis()));
        baris.push_back(daftarFilm[i].getPencipta());

        // Atribut Film
        baris.push_back(daftarFilm[i].getGenre());
        baris.push_back(to_string(daftarFilm[i].getDurasi()) + " menit");
        baris.push_back("Rp" + to_string(daftarFilm[i].getHarga()));

        // Atribut FilmAnimasi
        baris.push_back(daftarFilm[i].getStudioAnimasi());
        baris.push_back(daftarFilm[i].getTeknikAnimasi());

        // Menggabungkan seluruh voice actor menjadi satu string
        string daftarVoiceActor = "";

        vector<string> voiceActor = daftarFilm[i].getPengisiSuara();

        for (int j = 0; j < voiceActor.size(); j++)
        {
            if (j > 0)
            {
                daftarVoiceActor += ", ";
            }

            daftarVoiceActor += voiceActor[j];
        }

        baris.push_back(daftarVoiceActor);

        data.push_back(baris);
    }

    // =========================
    // HEADER TABEL
    // =========================

    vector<string> header = {
        "ID",
        "Judul",
        "Tahun Rilis",
        "Pencipta",
        "Genre",
        "Durasi",
        "Harga",
        "Studio Animasi",
        "Teknik Animasi",
        "Pengisi Suara"};

    // =========================
    // MENENTUKAN LEBAR KOLOM
    // =========================

    // Awalnya lebar kolom mengikuti panjang header.
    vector<int> lebarKolom(header.size());

    for (int i = 0; i < header.size(); i++)
    {
        lebarKolom[i] = header[i].length();
    }

    // Membandingkan dengan panjang setiap data.
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (data[i][j].length() > lebarKolom[j])
            {
                lebarKolom[j] = data[i][j].length();
            }
        }
    }

    // =========================
    // MENAMPILKAN JUDUL
    // =========================

    cout << "\n";
    cout << "========================================== DAFTAR FILM ANIMASI ==========================================" << endl;

    // =========================
    // MENAMPILKAN GARIS ATAS
    // =========================

    buatGaris(lebarKolom);

    // =========================
    // MENAMPILKAN HEADER
    // =========================

    cout << "|";

    for (int i = 0; i < header.size(); i++)
    {
        cout << " "
             << left
             << setw(lebarKolom[i])
             << header[i]
             << " |";
    }

    cout << endl;

    buatGaris(lebarKolom);

    // =========================
    // MENAMPILKAN DATA
    // =========================

    for (int i = 0; i < data.size(); i++)
    {
        cout << "|";

        for (int j = 0; j < data[i].size(); j++)
        {
            cout << " "
                 << left
                 << setw(lebarKolom[j])
                 << data[i][j]
                 << " |";
        }

        cout << endl;
    }

    // =========================
    // MENAMPILKAN GARIS BAWAH
    // =========================

    buatGaris(lebarKolom);
}

int main()
{
    // =========================
    // DATA PENGISI SUARA
    // =========================

    // Setiap film dapat memiliki beberapa pengisi suara utama.
    vector<string> pengisiSuara1 = {
        "Natsuki Hanae",
        "Akari Kito",
        "Satoshi Hino"};

    vector<string> pengisiSuara2 = {
        "Megumi Ogata",
        "Kana Hanazawa",
        "Yuichi Nakamura"};

    vector<string> pengisiSuara3 = {
        "Ryunosuke Kamiki",
        "Mone Kamishiraishi"};

    vector<string> pengisiSuara4 = {
        "Kaori Nazuka",
        "Suichi Ikeda",
        "Mayumi Tanaka"};

    vector<string> pengisiSuara5 = {
        "Soma Santoki",
        "Masaki Suda",
        "Takuya Kimura"};

    // =========================
    // 5 OBJECT FILMANIMASI
    // =========================

    FilmAnimasi film1(
        "F001",
        "Demon Slayer: Mugen Train",
        2020,
        "Koyoharu Gotouge",
        "Action, Fantasy",
        117,
        50000,
        "Ufotable",
        "2D Digital",
        pengisiSuara1);

    FilmAnimasi film2(
        "F002",
        "Jujutsu Kaisen 0",
        2021,
        "Gege Akutami",
        "Action, Fantasy",
        105,
        45000,
        "MAPPA",
        "2D Digital",
        pengisiSuara2);

    FilmAnimasi film3(
        "F003",
        "Your Name",
        2016,
        "Makoto Shinkai",
        "Romance, Fantasy",
        106,
        45000,
        "CoMix Wave Films",
        "2D Digital",
        pengisiSuara3);

    FilmAnimasi film4(
        "F004",
        "One Piece Film: Red",
        2022,
        "Eiichiro Oda",
        "Action, Adventure",
        115,
        50000,
        "Toei Animation",
        "2D Digital",
        pengisiSuara4);

    FilmAnimasi film5(
        "F005",
        "The Boy and the Heron",
        2023,
        "Hayao Miyazaki",
        "Fantasy, Adventure",
        124,
        55000,
        "Studio Ghibli",
        "2D Hand-drawn",
        pengisiSuara5);

    // =========================
    // VECTOR OF OBJECT
    // =========================

    // vector digunakan untuk menyimpan sekumpulan object FilmAnimasi.
    vector<FilmAnimasi> daftarFilm;

    // Memasukkan kelima object ke dalam vector.
    daftarFilm.push_back(film1);
    daftarFilm.push_back(film2);
    daftarFilm.push_back(film3);
    daftarFilm.push_back(film4);
    daftarFilm.push_back(film5);

    int pilihan;

    do
    {
        cout << "\n==============================\n";
        cout << "      MENU FILM ANIMASI       \n";
        cout << "==============================\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "0. Keluar\n";

        pilihan = inputInteger("Pilihan: ");

        switch (pilihan)
        {
        case 1:
            tambahFilm(daftarFilm);
            break;

        case 2:
            tampilkanSemuaFilm(daftarFilm);
            break;

        case 0:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "Error: pilihan menu tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}