public class Film extends KaryaSeni
{
    // =========================
    // ATTRIBUTE
    // =========================

    protected String genre;
    protected int durasi;
    protected int harga;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong
    public Film()
    {
    }

    // Constructor berparameter
    public Film(
        String id,
        String judul,
        int tahunRilis,
        String pencipta,
        String genre,
        int durasi,
        int harga
    )
    {
        // Memanggil constructor parent class.
        super(id, judul, tahunRilis, pencipta);

        this.genre = genre;
        this.durasi = durasi;
        this.harga = harga;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter Genre
    public void setGenre(String genre)
    {
        this.genre = genre;
    }

    public String getGenre()
    {
        return genre;
    }

    // Setter dan getter Durasi
    public void setDurasi(int durasi)
    {
        if (durasi >= 0 && durasi <= 600)
        {
            this.durasi = durasi;
        }
        else if (durasi < 0)
        {
            System.out.println(
                "Error: durasi tidak boleh negatif."
            );
        }
        else
        {
            System.out.println(
                "Error: durasi film tidak masuk akal. "
                + "Maksimal 600 menit."
            );
        }
    }

    public int getDurasi()
    {
        return durasi;
    }

    // Setter dan getter Harga
    public void setHarga(int harga)
    {
        if (harga >= 0 && harga <= 1000000)
        {
            this.harga = harga;
        }
        else if (harga < 0)
        {
            System.out.println(
                "Error: harga tidak boleh negatif."
            );
        }
        else
        {
            System.out.println(
                "Error: harga tiket tidak masuk akal. "
                + "Maksimal Rp1000000."
            );
        }
    }

    public int getHarga()
    {
        return harga;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi film.
    public void tampilkanInfo()
    {
        System.out.println("ID              : " + id);
        System.out.println("Judul           : " + judul);
        System.out.println("Tahun Rilis     : " + tahunRilis);
        System.out.println("Pencipta        : " + pencipta);
        System.out.println("Genre           : " + genre);
        System.out.println("Durasi          : " + durasi + " menit");
        System.out.println("Harga           : Rp" + harga);
    }
}