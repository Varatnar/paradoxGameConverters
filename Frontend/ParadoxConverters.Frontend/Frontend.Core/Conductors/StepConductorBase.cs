﻿

namespace Frontend.Core.ViewModels
{
    using Caliburn.Micro;
    using System.Linq;
    using Frontend.Core.ViewModels.Interfaces;
    using System.Collections.ObjectModel;
    using Frontend.Core.ViewModels.Interfaces;

    public abstract class StepConductorBase : ViewModelBase, IStepConductorBase
    {
        private ObservableCollection<IStep> steps;
        private IStep currentStep;

        public StepConductorBase(IEventAggregator eventAggregator)
            : base(eventAggregator)
        {
        }

        public ObservableCollection<IStep> Steps
        {
            get
            {
                return this.steps ?? (this.steps = new ObservableCollection<IStep>());
            }
        }

        public IStep CurrentStep
        {
            get
            {
                return this.currentStep;
            }
        }

        public virtual bool CanMoveForward
        {
            get
            {
                if (this.Steps.Last() == this.CurrentStep)
                {
                    return false;
                }

                return true;
            }
        }

        public virtual bool CanMoveBackward
        {
            get
            {
                if (this.Steps.First() == this.CurrentStep)
                {
                    return false;
                }

                return true;
            }
        }

        public void MoveToStep(IStep step)
        {
            if (this.currentStep == step)
            {
                return;
            }
            
            if (this.CurrentStep != null)
            {
                this.CurrentStep.Unload();
            }

            step.Load(null);

            this.currentStep = step;
            this.NotifyOfPropertyChange(() => this.CurrentStep);
        }
    }
}
