using namespace std;

class FilmAnimasi : public Film
{
private:
    // =========================
    // ATTRIBUTE
    // =========================

    // Nama studio yang memproduksi atau mengerjakan
    // animasi dari film tersebut.
    string studioAnimasi;

    // Teknik utama yang digunakan dalam pembuatan animasi,
    // misalnya 2D Digital, 3D, atau Stop Motion.
    string teknikAnimasi;

    // Menyimpan daftar pengisi suara utama dalam film animasi.
    // Menggunakan vector karena satu film dapat memiliki
    // lebih dari satu pengisi suara.
    vector<string> pengisiSuara;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    FilmAnimasi() {}

    // Constructor berparameter.
    // Constructor parent Film dipanggil melalui initializer list.
    // Karena Film sendiri merupakan turunan dari KaryaSeni,
    // pemanggilan constructor Film juga akan meneruskan proses
    // pembangunan bagian KaryaSeni.
    // Setelah bagian Film selesai diinisialisasi, body constructor
    // digunakan untuk mengisi atribut khusus FilmAnimasi.
    FilmAnimasi(string id, string judul, int tahunRilis, string pencipta,
                string genre, int durasi, int harga,
                string studioAnimasi, string teknikAnimasi,
                vector<string> pengisiSuara)
        : Film(id, judul, tahunRilis, pencipta, genre, durasi, harga)
    {
        this->studioAnimasi = studioAnimasi;
        this->teknikAnimasi = teknikAnimasi;
        this->pengisiSuara = pengisiSuara;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter studioAnimasi digunakan untuk mengubah
    // nama studio animasi.
    void setStudioAnimasi(string studioAnimasi)
    {
        this->studioAnimasi = studioAnimasi;
    }

    // Getter studioAnimasi digunakan untuk mengambil
    // nama studio animasi.
    string getStudioAnimasi() const
    {
        return studioAnimasi;
    }

    // Setter teknikAnimasi digunakan untuk mengubah
    // teknik animasi yang digunakan.
    void setTeknikAnimasi(string teknikAnimasi)
    {
        this->teknikAnimasi = teknikAnimasi;
    }

    // Getter teknikAnimasi digunakan untuk mengambil
    // teknik animasi yang digunakan.
    string getTeknikAnimasi() const
    {
        return teknikAnimasi;
    }

    // Setter pengisiSuara digunakan untuk mengganti
    // seluruh daftar pengisi suara.
    void setPengisiSuara(vector<string> pengisiSuara)
    {
        this->pengisiSuara = pengisiSuara;
    }

    // Getter pengisiSuara digunakan untuk mengambil
    // daftar seluruh pengisi suara.
    vector<string> getPengisiSuara() const
    {
        return pengisiSuara;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi FilmAnimasi,
    // termasuk atribut yang diwarisi dari KaryaSeni dan Film.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Judul           : " << judul << endl;
        cout << "Tahun Rilis     : " << tahunRilis << endl;
        cout << "Pencipta        : " << pencipta << endl;
        cout << "Genre           : " << genre << endl;
        cout << "Durasi          : " << durasi << " menit" << endl;
        cout << "Harga           : Rp" << harga << endl;
        cout << "Studio Animasi  : " << studioAnimasi << endl;
        cout << "Teknik Animasi  : " << teknikAnimasi << endl;

        cout << "Pengisi Suara   : ";

        // Menampilkan setiap nama pengisi suara yang
        // tersimpan di dalam vector.
        for (int i = 0; i < pengisiSuara.size(); i++)
        {
            cout << pengisiSuara[i];

            // Memberikan koma setelah setiap nama,
            // kecuali nama terakhir.
            if (i < pengisiSuara.size() - 1)
            {
                cout << ", ";
            }
        }

        cout << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object FilmAnimasi
    // dihancurkan.
    ~FilmAnimasi()
    {
    }
};