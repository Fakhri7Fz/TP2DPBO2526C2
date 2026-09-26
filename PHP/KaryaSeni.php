<?php

class KaryaSeni
{
    // =========================
    // ATTRIBUTE
    // =========================

    protected $id;
    protected $judul;
    protected $tahunRilis;
    protected $pencipta;

    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor dengan nilai default.
    // Nilai default memungkinkan object dibuat tanpa
    // harus langsung memberikan seluruh parameter.
    public function __construct(
        $id = "",
        $judul = "",
        $tahunRilis = 0,
        $pencipta = ""
    ) {
        $this->id = $id;
        $this->judul = $judul;
        $this->tahunRilis = $tahunRilis;
        $this->pencipta = $pencipta;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter dan getter ID
    public function setId($id)
    {
        $this->id = $id;
    }

    public function getId()
    {
        return $this->id;
    }

    // Setter dan getter Judul
    public function setJudul($judul)
    {
        $this->judul = $judul;
    }

    public function getJudul()
    {
        return $this->judul;
    }

    // Setter dan getter Tahun Rilis
    public function setTahunRilis($tahunRilis)
    {
        $this->tahunRilis = $tahunRilis;
    }

    public function getTahunRilis()
    {
        return $this->tahunRilis;
    }

    // Setter dan getter Pencipta
    public function setPencipta($pencipta)
    {
        $this->pencipta = $pencipta;
    }

    public function getPencipta()
    {
        return $this->pencipta;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Method untuk menampilkan informasi karya seni.
    public function tampilkan_info()
    {
        echo "ID              : " . $this->id . "<br>";
        echo "Judul           : " . $this->judul . "<br>";
        echo "Tahun Rilis     : " . $this->tahunRilis . "<br>";
        echo "Pencipta        : " . $this->pencipta . "<br>";
    }
}
?>