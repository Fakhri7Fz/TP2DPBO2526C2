using namespace std;

class Film : public KaryaSeni
{
protected:
    // =========================
    // ATTRIBUTE
    // =========================

    // Genre menunjukkan kategori atau tema cerita film,
    // misalnya Action, Comedy, Drama, Horror, dan sebagainya.
    string genre;

    // Durasi menyimpan lama film dalam satuan menit.
    int durasi;

    // Harga menunjukkan harga tiket untuk menonton film di bioskop.
    int harga;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini tetap dibuat agar object Film dapat
    // dibuat tanpa memberikan nilai awal.
    Film() {}

    // Constructor berparameter.
    // Constructor parent KaryaSeni dipanggil melalui initializer list untuk menginisialisasi bagian KaryaSeni dari object Film.
    // Setelah bagian KaryaSeni selesai diinisialisasi, body constructor digunakan untuk mengisi atribut yang memang milik Film.
    Film(string id, string judul, int tahunRilis, string pencipta, string genre, int durasi, int harga)
        : KaryaSeni(id, judul, tahunRilis, pencipta)
    {
        this->genre = genre;
        this->durasi = durasi;
        this->harga = harga;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter genre digunakan untuk mengubah nilai genre film.
    void setGenre(string genre)
    {
        this->genre = genre;
    }

    // Getter genre digunakan untuk mengambil nilai genre film.
    string getGenre() const
    {
        return genre;
    }

    // Setter durasi digunakan untuk mengubah durasi film.
    // Durasi dibatasi dari 0 sampai 600 menit.
    void setDurasi(int durasi)
    {
        if (durasi >= 0 && durasi <= 600)
        {
            this->durasi = durasi;
        }
        else if (durasi < 0)
        {
            cout << "Error: durasi tidak boleh negatif.\n";
        }
        else
        {
            cout << "Error: durasi film tidak masuk akal. " << "Maksimal 600 menit.\n";
        }
    }

    // Getter durasi digunakan untuk mengambil durasi film.
    int getDurasi() const
    {
        return durasi;
    }

    // Setter harga digunakan untuk mengubah harga tiket.
    // Harga dibatasi dari Rp0 sampai Rp1.000.000.
    void setHarga(int harga)
    {
        if (harga >= 0 && harga <= 1000000)
        {
            this->harga = harga;
        }
        else if (harga < 0)
        {
            cout << "Error: harga tidak boleh negatif.\n";
        }
        else
        {
            cout << "Error: harga tiket tidak masuk akal. " << "Maksimal Rp1000000.\n";
        }
    }

    // Getter harga digunakan untuk mengambil harga tiket.
    int getHarga() const
    {
        return harga;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan informasi Film.
    // Method ini juga menampilkan informasi yang diwarisi
    // dari KaryaSeni.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Judul           : " << judul << endl;
        cout << "Tahun Rilis     : " << tahunRilis << endl;
        cout << "Pencipta        : " << pencipta << endl;
        cout << "Genre           : " << genre << endl;
        cout << "Durasi          : " << durasi << " menit" << endl;
        cout << "Harga           : Rp" << harga << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object Film dihancurkan.
    ~Film()
    {
    }
};