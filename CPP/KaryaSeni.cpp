using namespace std;

class KaryaSeni
{
protected:
    // =========================
    // ATTRIBUTE
    // =========================

    // ID digunakan sebagai identitas unik dari setiap karya seni.
    // Dibuat protected agar class turunan seperti Film dapat
    // mengaksesnya secara langsung jika diperlukan.
    string id;

    // Judul merupakan nama dari karya seni.
    string judul;

    // Tahun ketika karya seni dirilis atau dipublikasikan.
    int tahunRilis;

    // Nama pencipta dari karya seni.
    string pencipta;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Digunakan ketika object dibuat tanpa memberikan nilai awal.
    KaryaSeni() {}

    // Constructor berparameter.
    // Digunakan untuk langsung memberikan nilai pada seluruh
    // atribut ketika object KaryaSeni dibuat.
    KaryaSeni(string id, string judul, int tahunRilis, string pencipta)
    {
        this->id = id;
        this->judul = judul;
        this->tahunRilis = tahunRilis;
        this->pencipta = pencipta;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter ID digunakan untuk mengubah nilai ID.
    void setId(string id)
    {
        this->id = id;
    }

    // Getter ID digunakan untuk mengambil nilai ID.
    // const digunakan karena method ini hanya membaca nilai
    // dan tidak mengubah atribut object.
    string getId() const
    {
        return id;
    }

    // Setter judul digunakan untuk mengubah judul karya seni.
    void setJudul(string judul)
    {
        this->judul = judul;
    }

    // Getter judul digunakan untuk mengambil judul karya seni.
    string getJudul() const
    {
        return judul;
    }

    // Setter tahunRilis digunakan untuk mengubah tahun rilis.
    void setTahunRilis(int tahunRilis)
    {
        this->tahunRilis = tahunRilis;
    }

    // Getter tahunRilis digunakan untuk mengambil tahun rilis.
    int getTahunRilis() const
    {
        return tahunRilis;
    }

    // Setter pencipta digunakan untuk mengubah nama pencipta.
    void setPencipta(string pencipta)
    {
        this->pencipta = pencipta;
    }

    // Getter pencipta digunakan untuk mengambil nama pencipta.
    string getPencipta() const
    {
        return pencipta;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi yang dimiliki oleh KaryaSeni.
    // const digunakan karena method ini hanya membaca data.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Judul           : " << judul << endl;
        cout << "Tahun Rilis     : " << tahunRilis << endl;
        cout << "Pencipta        : " << pencipta << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object KaryaSeni dihancurkan.
    // Saat ini tidak ada resource khusus yang perlu dibersihkan,
    // sehingga isi destructor dikosongkan.
    ~KaryaSeni()
    {
    }
};