public class KaryaSeni
{
    // =========================
    // ATTRIBUTE
    // =========================

    protected String id;
    protected String judul;
    protected int tahunRilis;
    protected String pencipta;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong
    public KaryaSeni()
    {
    }

    // Constructor berparameter
    public KaryaSeni(
        String id,
        String judul,
        int tahunRilis,
        String pencipta
    )
    {
        this.id = id;
        this.judul = judul;
        this.tahunRilis = tahunRilis;
        this.pencipta = pencipta;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter ID
    public void setId(String id)
    {
        this.id = id;
    }

    public String getId()
    {
        return id;
    }

    // Setter dan getter Judul
    public void setJudul(String judul)
    {
        this.judul = judul;
    }

    public String getJudul()
    {
        return judul;
    }

    // Setter dan getter Tahun Rilis
    public void setTahunRilis(int tahunRilis)
    {
        this.tahunRilis = tahunRilis;
    }

    public int getTahunRilis()
    {
        return tahunRilis;
    }

    // Setter dan getter Pencipta
    public void setPencipta(String pencipta)
    {
        this.pencipta = pencipta;
    }

    public String getPencipta()
    {
        return pencipta;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi karya seni.
    public void tampilkanInfo()
    {
        System.out.println("ID              : " + id);
        System.out.println("Judul           : " + judul);
        System.out.println("Tahun Rilis     : " + tahunRilis);
        System.out.println("Pencipta        : " + pencipta);
    }
}