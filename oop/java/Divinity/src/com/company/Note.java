package com.company;

public class Note extends Item{

    String Text;
    String name = "Note";

    @java.lang.Override
    public void setName(String name) {
        super.setName(name);
    }

    public Note(String text) {
        Text = text;
    }
}
