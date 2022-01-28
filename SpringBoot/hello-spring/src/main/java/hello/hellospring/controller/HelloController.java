package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloController {
    @GetMapping("hello") //url뒤 /hello오면 작동
    public String hello(Model model){
        model.addAttribute("data","spring!!");
        return "hello";
    }

    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam(value="name")String name,@RequestParam(value="adder")String adder, Model model){
        model.addAttribute("name",name);
        model.addAttribute("adder",adder);
        return "hello-template";
    }
}
