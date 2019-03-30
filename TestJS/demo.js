

require('UIButton','UIColor');

defineClass('ViewController', {
            teset: function() {
            //            super.viewDidLoad();
            // Do any additional setup after loading the view, typically from a nib.
            console.log('click btn ');
            var btn = UIButton.alloc().initWithFrame({x:20, y:20, width:100, height:100});
            btn.setTitle_forState("My test", 0);
            btn.addTarget_action_forControlEvents(self, "run_inNative", 1<<6);
            self.view().addSubview(btn);
            btn.setBackgroundColor(UIColor.redColor());
            },
            runInJS:function(){
            self.run_inNative();
            },
            runInJS1:function(){
            console.log('run_inJS1');
            },
            
            });
