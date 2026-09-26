import java.util.ArrayList;

public class FilmAnimasi extends Film
{
    // =========================
    // ATTRIBUTE
    // =========================

    private String studioAnimasi;
    private String teknikAnimasi;
    private ArrayList<String> pengisiSuara;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong
    public FilmAnimasi()
    {
        pengisiSuara = new ArrayList<>();
    }

    // Constructor berparameter
    public FilmAnimasi(
        String id,
        String judul,
        int tahunRilis,
        String pencipta,
        String genre,
        int durasi,
        int harga,
        String studioAnimasi,
        String teknikAnimasi,
        ArrayList<String> pengisiSuara
    )
    {
        // Memanggil constructor parent class Film.
        super(
            id,
            judul,
            tahunRilis,
            pencipta,
            genre,
            durasi,
            harga
        );

        this.studioAnimasi = studioAnimasi;
        this.teknikAnimasi = teknikAnimasi;
        this.pengisiSuara = pengisiSuara;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter Studio Animasi
    public void setStudioAnimasi(String studioAnimasi)
    {
        this.studioAnimasi = studioAnimasi;
    }

    public String getStudioAnimasi()
    {
        return studioAnimasi;
    }

    // Setter dan getter Teknik Animasi
    public void setTeknikAnimasi(String teknikAnimasi)
    {
        this.teknikAnimasi = teknikAnimasi;
    }

    public String getTeknikAnimasi()
    {
        return teknikAnimasi;
    }

    // Setter dan getter Pengisi Suara
    public void setPengisiSuara(ArrayList<String> pengisiSuara)
    {
        this.pengisiSuara = pengisiSuara;
    }

    public ArrayList<String> getPengisiSuara()
    {
        return pengisiSuara;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi film animasi.
    public void tampilkanInfo()
    {
        System.out.println("ID              : " + id);
        System.out.println("Judul           : " + judul);
        System.out.println("Tahun Rilis     : " + tahunRilis);
        System.out.println("Pencipta        : " + pencipta);
        System.out.println("Genre           : " + genre);
        System.out.println("Durasi          : " + durasi + " menit");
        System.out.println("Harga           : Rp" + harga);
        System.out.println("Studio Animasi  : " + studioAnimasi);
        System.out.println("Teknik Animasi  : " + teknikAnimasi);

        System.out.println("Pengisi Suara   :");

        for (String voiceActor : pengisiSuara)
        {
            System.out.println("- " + voiceActor);
        }
    }
}